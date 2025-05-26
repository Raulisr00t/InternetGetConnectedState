# Reversed `wininet.dll` – Internet Connectivity & Registry Analysis

This repository contains a reverse engineering analysis of the `wininet.dll` library on Windows, with a focus on the `InternetGetConnectedStateExW` function and how Windows evaluates Internet connectivity using registry-based settings.

## 🔍 Key Highlights

- Disassembly and analysis of `InternetGetConnectedStateExW`
- Understanding how Windows infers network status via:
  - Registry keys
  - System flags
  - Internal wininet checks
- Potential implications for:
  - Malware sandbox evasion
  - Red team emulation
  - Security research

## ⚠️ Security Research Disclaimer

This repository is intended for **educational and research purposes only**. The goal is to understand Windows internals and aid defensive and analytical efforts. Do not use this knowledge to build or support malicious tools.

## 🧠 Observations

- `InternetGetConnectedStateExW` can return a "connected" state based on **registry configurations**, even without real Internet access.
- Malware or red team tools using this API can be **tricked** by modifying or spoofing related values.
- Deeper inspection (DNS, socket connections) is required for reliable connectivity validation.

## 🛠️ Usage

Use this project to:

- Simulate online/offline states in malware analysis environments
- Study how legacy Windows APIs behave under different configurations
- Patch wininet behavior for testing or research

## 📚 Registry Paths Accessed by InternetGetConnectedStateExW
✅ Read Operations

These registry keys are accessed to read configuration or policy enforcement settings:
```registry
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Internet Settings
HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Internet Settings
HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\Internet Settings
HKEY_CURRENT_USER\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\Internet Settings
```

## 🔍 Queried Values

Here are the specific values being read from the above paths:

DisableCachingOfSSLPages
DisableHttp2ConnectionSharing
EnableTlsAnonymousClientAuthFallback
DisableProxyAuthenticationSchemes
DisableProxyLinkLocalNameResolution
EnableInsecureTlsFallback

## 📚 References

- [Microsoft Docs – InternetGetConnectedStateExW](https://learn.microsoft.com/en-us/windows/win32/api/wininet/nf-wininet-internetgetconnectedstateexw)
- Internal Windows registry paths:
  - `HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings`
  - `HKLM\Software\Policies\Microsoft\Windows\CurrentVersion\Internet Settings`

## ⚠️ Research Note: API Usage Advice

The `InternetGetConnectedStateExW` function relies heavily on registry values and internal heuristics — which **can be easily manipulated or spoofed** in sandbox or defensive environments. As such, it is **not reliable** for determining real Internet connectivity in adversarial contexts.

### 🔄 Recommended Alternatives

For more accurate network checks, consider using:

- `getaddrinfo()`, `connect()`, or raw `socket()` calls to known Internet IPs
- `WinHttpSendRequest()` with `WinHttpOpenRequest()` for outbound HTTP checks
- `Custom TCP/UDP probes or DNS resolution attempts`

These approaches perform **actual network activity**, which is harder to fake and provides stronger assurance of real connectivity.

---

**Knowledge is neutral — use it responsibly.**

## 👤 Author

Reverse engineering and documentation by Raul.

---

**Contributions, suggestions, or corrections are welcome!**

---
