# ESP32 Relay Control (PlatformIO + Arduino)

Assignment วิชา 030143375 Internet of Things for Industrial Applications — Week 12: GitHub

## รายละเอียด
ควบคุมรีเลย์ด้วยคำสั่งผ่าน Serial Monitor พร้อม LED กะพริบแสดงสถานะ

| อุปกรณ์ | ขา ESP32 |
|---|---|
| Relay | GPIO 26 |
| LED (on-board) | GPIO 2 |

## วิธีใช้งาน
1. เปิดโปรเจคด้วย VS Code + PlatformIO
2. Upload: `pio run -t upload`
3. เปิด Serial Monitor (115200 baud) แล้วพิมพ์ `ON` หรือ `OFF`

## ประวัติการแก้ไขโค้ด
| ขั้นตอน | รายละเอียด |
|---|---|
| Version 1 | ใช้ `delay(1000)` กะพริบ LED |
| ปัญหา | [Issue #1](../../issues/1) — รีเลย์ตอบสนองช้า 1–2 วินาที เพราะ `delay()` ทำให้ loop หยุดรอ |
| การแก้ไข | แตก branch `fix-nonblocking` เปลี่ยนเป็น `millis()` (non-blocking) |
| Merge | [Pull Request #2](../../pull/2) — ดูโค้ดที่แก้ได้ในแท็บ Files changed |

### Workflow ที่ใช้
```
main ──●── first commit
       │
       ●── Add relay control (delay)
       │\
       │ ●── fix-nonblocking: replace delay() with millis()
       │/
       ●── Merge PR #2
```