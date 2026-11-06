# TFLite Micro on Ubuntu ARM64 (Apple Silicon) (v1.0)

(c) 2025-2026, Edo. Franzi 



Installation and build guide for **Ubuntu 26.10 ARM64 (aarch64)** running under **VMware Fusion on an Apple M1**.

This guide supplements the uKOS-X `README.md` and describes the adjustments required on an **ARM64 host**. The original uKOS scripts, including `build.sh`, remain unchanged.

## Python 3.13.18

TFLite Micro still requires **Python 3.13**. Unfortunately, Ubuntu 26.10 provides **Python 3.14** by default, and the required Python version cannot be installed directly using `apt`.

### OpenSSL 3.5.4

For this setup, Python 3.13.18 is built against a private OpenSSL 3 installation rather than the system OpenSSL installation. The following uKOS directory layout is used:

```bash
/opt/uKOS/Packages/,Sources/openssl-3.5.4.tar.gz    # Downloaded archive
/opt/uKOS/Packages/openssl-3.5.4                    # Extracted source tree
/opt/uKOS/local                                     # Installation prefix
```

The directories `/opt/uKOS/Packages/,Sources`, `/opt/uKOS/Packages`, and `/opt/uKOS/local` already exist in the uKOS installation. Download the archive to `/opt/uKOS/Packages/,Sources`, extract it into `/opt/uKOS/Packages`, and install it into `/opt/uKOS/local`:

```bash
sudo apt update
sudo apt install -y build-essential wget ca-certificates zlib1g-dev \
    libbz2-dev libreadline-dev libsqlite3-dev libffi-dev liblzma-dev \
    tk-dev xz-utils

wget -O "/opt/uKOS/Packages/,Sources/openssl-3.5.4.tar.gz" \
    https://www.openssl.org/source/openssl-3.5.4.tar.gz
tar -xf "/opt/uKOS/Packages/,Sources/openssl-3.5.4.tar.gz" -C /opt/uKOS/Packages
cd /opt/uKOS/Packages/openssl-3.5.4

./Configure --prefix=/opt/uKOS/local --openssldir=/opt/uKOS/local/ssl shared
make -j"$(nproc)"
make install_sw
```

> These commands describe a reproducible procedure. Not every option used in the original OpenSSL build was recorded.

#### HTTPS certificates: required configuration

With this private OpenSSL installation, Python looks for certificates under `/opt/uKOS/local/ssl`. If the certificate store is missing, HTTPS requests may fail with:

```text
SSL: CERTIFICATE_VERIFY_FAILED
```

Link the Ubuntu certificate store to the private OpenSSL installation:

```bash
mkdir -p /opt/uKOS/local/ssl
ln -sfn /etc/ssl/certs/ca-certificates.crt /opt/uKOS/local/ssl/cert.pem
ln -sfn /etc/ssl/certs /opt/uKOS/local/ssl/certs
```

**Caution:** Do not overwrite an existing, populated `certs` directory without inspecting it first. The commands above assume the destination does not exist or is already a symbolic link. Also, `/opt/uKOS/local` may contain other uKOS installations: do not delete that directory when resetting OpenSSL.

After installing Python, test HTTPS connectivity:

```bash
python -c "import urllib.request; print(urllib.request.urlopen('https://github.com').status)"
# Expected result: 200
```

### Python 3.13.18 — building from source in the uKOS directory layout

A previously created virtual environment used **Python 3.14.10**, despite having a name that suggested Python 3.13. The TensorFlow version required by TFLM was not available for that interpreter. Use **Python 3.13.18** explicitly.

Download the Python source archive to the existing `/opt/uKOS/Packages/,Sources` directory, extract it under `/opt/uKOS/Packages`, build it in a separate directory under `/opt/uKOS/build`, and install it under `/opt/uKOS/cross/python-3.13.18`:

```bash
/opt/uKOS/Packages/,Sources/Python-3.13.18.tgz  # Downloaded archive
/opt/uKOS/Packages/Python-3.13.18/              # Extracted sources
/opt/uKOS/build/Python-3.13.18/                 # Out-of-tree build
/opt/uKOS/cross/python-3.13.18/                 # Installation prefix
```

#### Download and extract

```bash
wget -O '/opt/uKOS/Packages/,Sources/Python-3.13.18.tgz' \
    https://www.python.org/ftp/python/3.13.18/Python-3.13.18.tgz
tar -xzf '/opt/uKOS/Packages/,Sources/Python-3.13.18.tgz' -C /opt/uKOS/Packages
```

#### Configure and build outside the source tree

Use the OpenSSL installation described above. Python must be able to locate its headers and libraries both at build time and at runtime.

```bash
mkdir -p /opt/uKOS/build/Python-3.13.18
chown "$(id -u):$(id -g)" /opt/uKOS/build/Python-3.13.18
cd /opt/uKOS/build/Python-3.13.18

export CPPFLAGS='-I/opt/uKOS/local/include'
export LDFLAGS='-L/opt/uKOS/local/lib64 -L/opt/uKOS/local/lib'

/opt/uKOS/Packages/Python-3.13.18/configure \
    --prefix=/opt/uKOS/cross/python-3.13.18 \
    --with-openssl=/opt/uKOS/local \
    --with-openssl-rpath=auto \
    --with-ensurepip=install

make -j"$(nproc)"
make install
```

> Your user account must have write access to the build directory. The `chown` above changes ownership **only** of the new Python build directory, not of `/opt/uKOS/build` as a whole. If `/opt/uKOS/local` uses a nonstandard library layout, inspect `config.log` and the installed `lib` and `lib64` directories before changing the flags.

#### Verify Python and HTTPS connectivity

```bash
# Expected: Python 3.13.18
/opt/uKOS/cross/python-3.13.18/bin/python3.13 --version

# Display the OpenSSL version
/opt/uKOS/cross/python-3.13.18/bin/python3.13 -c 'import ssl; print(ssl.OPENSSL_VERSION)'

# Expected HTTPS status: 200
/opt/uKOS/cross/python-3.13.18/bin/python3.13 -c \
    "import urllib.request; print(urllib.request.urlopen('https://github.com').status)"
```

If HTTPS verification fails, check the OpenSSL certificate links described above. Do not disable certificate verification.

#### Create the TFLM virtual environment

```bash
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv"
/opt/uKOS/cross/python-3.13.18/bin/python3.13 -m venv Tflite_Pyenv
source Tflite_Pyenv/bin/activate

# Python 3.13.18
python --version
python -m pip install --upgrade pip
pip install -r requirements.txt
```

**Important:** Run `pip` from within the activated virtual environment, as recommended in the original uKOS-X README. The name of a virtual environment does not determine which Python version it uses.

To reactivate the environment in a new terminal:

```bash
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv"
source Tflite_Pyenv/bin/activate
```

## Configuring `~/.zshrc`

No `pyenv` configuration is required when using this source-built Python. Define the uKOS package root only if it has not already been configured:

```bash
nano ~/.zshrc
```

```bash
# uKOS-X package root (unless defined elsewhere)
export PATH_UKOS_X_PACKAGE="$HOME/uKOS_Soft/OS_Kernel-X"

# Optional: make the dedicated Python 3.13 installation easy to find
export PATH="/opt/uKOS/cross/python-3.13.18/bin:$PATH"
```

Reload and verify:

```bash
source ~/.zshrc
python3.13 --version
```

The explicit Python path used above works even if you omit the optional `PATH` entry. **Do not add** global `MAKEFLAGS` or `SKIP_DOWNLOADS=1` settings:

```bash
unset MAKEFLAGS SKIP_DOWNLOADS
printenv MAKEFLAGS       # No output expected
```

Setting `SKIP_DOWNLOADS=1` globally prevents the download of required **CMSIS-NN** dependencies. The ARM64 launcher described below applies the RISC-V override only to the relevant Make invocation.

> `~/.zshrc` is the standard zsh configuration file; no additional hidden directory is needed.

## Building with `build-64.sh`,  keeping `build.sh` unchanged

### RISC-V toolchain issue on an ARM64 host

The original uKOS `build.sh` removes and reclones the `Tflite-micro` source tree. During the `RV64IMAFDC` build, the TFLM Makefile downloads an old **Linux x86-64** compiler:

```bash
riscv64-unknown-elf-gcc-20181030-x86_64-linux-ubuntu14.tar.gz
ELF: not found
Syntax error: word unexpected
```

This compiler cannot run on an **aarch64** host. A compatible toolchain is already installed at:

```bash
/opt/uKOS/cross/gcc-16.2.0/riscv/bin/riscv64-unknown-elf-g++
```

Verify it:

```bash
# ELF 64-bit ... ARM aarch64
file /opt/uKOS/cross/gcc-16.2.0/riscv/bin/riscv64-unknown-elf-g++

# GCC 16.2.0
/opt/uKOS/cross/gcc-16.2.0/riscv/bin/riscv64-unknown-elf-g++ --version
```

**Do not** attempt to fix this by creating a symbolic link inside `Tflite-micro/.../downloads`: `build.sh` removes that directory during each rebuild.

### Visible files to create

Create the following two **visible** additions under `Third_Parties/Tflite-micro`:

```bash
Tflite-micro/
├── build.sh                # Original uKOS script; unchanged
├── build-64.sh             # New ARM64 launcher
├── make-64/                # Visible directory
│   └── make               # GNU Make wrapper
├── Construction/
└── Tflite-micro/           # Clone regenerated by build.sh
```

### GNU Make wrapper: `make-64/make`

```bash
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro"
mkdir -p make-64
nano make-64/make
```

File contents:

```bash
#!/usr/bin/env bash

REAL_MAKE=/usr/bin/make

for arg in "$@"; do
    if [[ "$arg" == "TARGET=riscv32_generic" ]]; then
        exec "$REAL_MAKE" "$@" \
            TARGET_TOOLCHAIN_ROOT=/opt/uKOS/cross/gcc-16.2.0/riscv/bin/ SKIP_DOWNLOADS=1
    fi
done

exec "$REAL_MAKE" "$@"
```

Make it executable:

```bash
chmod +x make-64/make
```

The wrapper adds these parameters only when Make receives `TARGET=riscv32_generic`. ARM/CMSIS-NN Make invocations retain their normal download behavior.

### ARM64 launcher: `build-64.sh`

```bash
nano build-64.sh
```

File contents:

```bash
#!/usr/bin/env bash
set -e

cd "$(dirname "$0")"

unset MAKEFLAGS SKIP_DOWNLOADS
export PATH="$PWD/make-64:$PATH"

exec ./build.sh "$@"
```

Make it executable:

```bash
chmod +x build-64.sh
```

**Note:** The initial troubleshooting procedure used a `.arm64-tools` directory and a `build-arm64.sh` launcher. The layout documented here uses the **visible** names `make-64` and `build-64.sh`. The approach is the same, but the files should be tested after creation.

## Build order

Activate the Python environment if necessary, then run **only** the ARM64 launcher:

```bash
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv"
source Tflite_Pyenv/bin/activate

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro"
./build-64.sh
```

**Do not run `./build.sh` separately afterward.** `build-64.sh` already invokes it with the appropriate environment.

### Troubleshooting summary

| Symptom                                                 | Cause                                                        | Fix                                                          |
| ------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `tensorflow==2.21.0` unavailable                        | Virtual environment used Python 3.14 instead of 3.13         | Build and install Python 3.13.18 under `/opt/uKOS/cross/python-3.13.18`, then recreate the venv |
| `CERTIFICATE_VERIFY_FAILED`                             | Private OpenSSL installation could not find trusted certificates | Link to Ubuntu's certificate store                           |
| `CMSIS download ... downloads directory does not exist` | Global `SKIP_DOWNLOADS=1` blocked dependency downloads     | Remove global `MAKEFLAGS`                                    |
| `ELF: not found` during RISC-V build                    | The downloaded compiler targets x86-64                           | Select the ARM64-hosted GCC 16.2.0 via the Make wrapper      |
| Symbolic-link fix disappears                            | `build.sh` reclones TFLM                                     | Keep the workaround outside the regenerated clone            |
| Git `detached HEAD` message                             | A specific Git revision is checked out                      | Informational message, not a build error                     |

## Building the uKOS-X example application

After building the libraries, follow the instructions in the uKOS-X README:

```bash
cd "${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_Neuros/class_TFL/_Training"
./build.sh

cd "${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_Neuros/class_TFL/Nucleo_H743"
make -j USER_MODE=1
```

---

**Key points:** Download OpenSSL to `/opt/uKOS/Packages/,Sources`, extract it in `/opt/uKOS/Packages`, install it in `/opt/uKOS/local`, build Python 3.13.18 out of tree under `/opt/uKOS/build` and install it under `/opt/uKOS/cross/python-3.13.18`, use the system certificate store for HTTPS, no global `MAKEFLAGS`, an unchanged uKOS `build.sh`, and **a single `./build-64.sh` invocation** on ARM64.