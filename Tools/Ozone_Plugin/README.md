Ozone uKOS-X RTOS Plugins
=========================

(c) 2025-2026, Edo. Franzi, 2026-10-24



These plugins enabled uKOS-X RTOS awareness in SEGGER Ozone debugger.

1. **uKOS-X.js: that uses Ozone SmartView display facilities in multi window.**
1. **uKOS-X_OS.js: that uses Ozone OS display facilities in multi window.**

Be sure that the latest Java package is installed.

Installation
------------

1. Lauch Ozone

2. Enable the plugin:

   1. **Enabling the SmartView plugin:** in Ozone consol type: Project.SetSmartViewPlugin("xyz/OS_Kernel-X/Tools/Ozone_Plugin/uKOS-X.js"). In this mode, it is possible to open many instances of the plugin.
   1. **Enabling the OS plugin:** in Ozone consol type: Project.SetOSPlugin("xyz/OS_Kernel-X/Tools/Ozone_Plugin/uKOS-X_OS.js"). In this mode, it is possible to open many instances of the plugin.

3. Add view from menu View/SmartView.

4. Select uKOS-Xfrom the menu View
