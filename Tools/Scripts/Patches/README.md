# Generic patches

(c) 2025-2026, Edo. Franzi

## Creating a patch

```bash
cd gcc-x.y.z/xyz
diff -u oldFile newFile > /Scripts/Patches/xyz/xyz.patch
```

## Applying a patch

```bash
cd gcc-x.y.z/xyz
patch -p1 -d . < /Scripts/Patches/xyz/xyz.patch
```

## Patches

1. **cortex**: for multilib fragment code to support Helium (necessary for gcc-15.2.0)
3. ~~**gdb**: for gdb version < 14.0~~
4. ~~**llvm**: for llvm-17.0.6~~
5. **riscv**: for multilib fragment code  (necessary for gcc-15.2.0)

