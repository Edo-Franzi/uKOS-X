

# Benchmarks

(c) 2025-2026, Edo. Franzi, 2026-03-24



### With µKOS-X V.0.2.34 and gcc-15.2.0

## Bench 00

```
; Goal:		Bench 00: 	Compute the X-Y projection and the histogram of
;	                    a small square array (50 x 50 uint8_t) elements.
;						          The data is located in the CPU internal memory
```

|                          | CoreMark/MHz     | _fill  [µs] | _projX  [µs] | _projY  [µs] | _histo  [µs] |
| ------------------------ | ---------------- | ----------- | ------------ | ------------ | ------------ |
| Nucleo_H743 @ 480-MHz    | 5.29             | 12          | 41           | 18           | 30           |
| Nucleo_N657 @ 800-MHz    | 4.40             | 19          | 29           | 23           | 31           |
| Discovery_U5G9 @ 160-MHz | 4.10             | 97          | 114          | 97           | 147          |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | 34          | 39           | 46           | 71           |

## Bench 01

```
; Goal:		Bench 01: 	Compute the X-Y projection and the histogram of
;						          a small square array (200 x 200 uint8_t) elements.
;						          The data is located in the CPU internal memory
```

|                          | CoreMark/MHz     | _fill  [µs] | _projX  [µs] | _projY  [µs] | _histo  [µs] |
| ------------------------ | ---------------- | ----------- | ------------ | ------------ | ------------ |
| Nucleo_H743 @ 480-MHz    | 5.29             | 254         | 671          | 288          | 450          |
| Nucleo_N657 @ 800-MHz    | 4.40             | 256         | 612          | 369          | 481          |
| Discovery_U5G9 @ 160-MHz | 4.10             | 1519        | 1771         | 1522         | 2018         |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | 538         | 585          | 728          | 1230         |

## Bench 02

```
; Goal:		Bench 02: 	Searching for the min / max of a small square array
;                     (1000 uint32_t) elements.
;						          The data is located in the CPU internal memory. 1000 iteractions.
```

|                          | CoreMark/MHz     | _minMax  [µs] |
| ------------------------ | ---------------- | ------------- |
| Nucleo_H743 @ 480-MHz    | 5.29             | 1131          |
| Nucleo_N657 @ 800-MHz    | 4.40             | 690           |
| Discovery_U5G9 @ 160-MHz | 4.10             | 2099          |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | 574           |

## Bench 03

```
; Goal:		Bench 03: 	Searching for the min / max of a big square array
;                     (50000 uint32_t) elements.
;						          The data is located in the internal memory; 100 iteractions.
```

|                          | CoreMark/MHz     | _minMax  [µs] |
| ------------------------ | ---------------- | ------------- |
| Nucleo_H743 @ 480-MHz    | 5.29             | 117           |
| Nucleo_N657 @ 800-MHz    | 4.40             | 79            |
| Discovery_U5G9 @ 160-MHz | 4.10             | 215           |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | 62            |

## Bench 04

```
; Goal:		Bench 04: 	Compute the atan2(x, y) by a cordic in a fixed point.
;						          The data is located in the external memory. 1000 iteractions.
```

|                          | CoreMark/MHz     | _atan2  [µs] |
| ------------------------ | ---------------- | ------------ |
| Nucleo_H743 @ 480-MHz    | 5.29             | 4152         |
| Nucleo_N657 @ 800-MHz    | 4.40             | 1695         |
| Discovery_U5G9 @ 160-MHz | 4.10             | 19866        |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | 1222         |

## Bench 05

```
; Goal:		Bench 05: 	Compute a simple loop. 1000000 iterations.
```

|                          | CoreMark/MHz     | _loop  [µs] |
| ------------------------ | ---------------- | ----------- |
| Nucleo_H743 @ 480-MHz    | 5.29             | 10400       |
| Nucleo_N657 @ 800-MHz    | 4.40             | 9930        |
| Discovery_U5G9 @ 160-MHz | 4.10             | -           |
| MAiXDUiNO_K210 @ 400-MHz | 1.7 (estimation) | -           |
