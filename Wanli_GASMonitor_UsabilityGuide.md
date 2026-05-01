
# Wanli GAS Monitor — Usability Guide

---

## Overview

Wanli GAS Monitor is a UE5 debug plugin that shows every Gameplay Ability activation attempt in real time. Instead of digging through logs or pausing the game, you get a live popup window: green for success, red for failure, plus a clear reason why.

Built for development only. No shipping overhead, no UMG — the UI uses Slate, so it stays lightweight and out of your render cost.

---

## Installation

**Move to a new project:**

1. Copy into your project’s `Plugins/` folder:
   ```
   Plugins/Wanli_GASMonitor/
     ├── Source/
     ├── Resources/
     └── Wanli_GASMonitor.uplugin
   ```
   Skip `Binaries/` and `Intermediate/`.

2. Right-click `.uproject` → **Generate Visual Studio project files**

3. Build the solution

4. Open UE → **Edit → Plugins**, search *Wanli GAS Monitor*, enable, restart

---

## Required Configuration

If this step is missing, failures show as **Unknown**.

Add to `DefaultGame.ini`:
```ini
[/Script/GameplayAbilities.AbilitySystemGlobals]
ActivateFailCanActivateAbilityTag=(TagName="Ability.ActivateFail.CanActivate")
ActivateFailCooldownTag=(TagName="Ability.ActivateFail.Cooldown")
ActivateFailCostTag=(TagName="Ability.ActivateFail.Cost")
ActivateFailNetworkingTag=(TagName="Ability.ActivateFail.Networking")
ActivateFailTagsBlockedTag=(TagName="Ability.ActivateFail.BlockedByTags")
ActivateFailTagsMissingTag=(TagName="Ability.ActivateFail.MissingTags")
```

Add to `DefaultGameplayTags.ini`:
```ini
+GameplayTagList=(Tag="Ability.ActivateFail.CanActivate")
+GameplayTagList=(Tag="Ability.ActivateFail.Cooldown")
+GameplayTagList=(Tag="Ability.ActivateFail.Cost")
+GameplayTagList=(Tag="Ability.ActivateFail.Networking")
+GameplayTagList=(Tag="Ability.ActivateFail.BlockedByTags")
+GameplayTagList=(Tag="Ability.ActivateFail.MissingTags")
```

Restart the editor.

---

## Adding the Component

Attach `UWanliGASMonitorComponent` to any actor with an ASC.

**Blueprint:**
- Add Component → *Wanli GAS Monitor*

**C++:**
```cpp
WanliMonitor = CreateDefaultSubobject<UWanliGASMonitorComponent>(TEXT("WanliGASMonitor"));
```

**Runtime toggle:**

| Property | Default | Effect |
|---|---|---|
| `bDisplayGASInfo` | true | Disable to ignore events |

---

## Reading the Window

Opens on first event. Reopens if closed.

```
[Time]  [Ability]   SUCCESS
[Time]  [Ability]   FAILED  →  Reason
```

- Green = success  
- Red = failure  

Max 100 entries.

---

## Failure Reasons

| Reason | Meaning |
|---|---|
| Cooldown | Still on cooldown |
| Cost | Not enough resource |
| Blocked | Blocked by tag |
| Missing Tags | Required tags missing |
| Networking | Prediction mismatch |
| Unknown | Config missing |

---

## Exporting Logs

Click **Export Log**

```
Saved/Wanli_GASMonitor_Log/
```

Example:
```
Wanli GAS Monitor — Export
--------------------------------
[21:41:16.384]  [GA_SwordSwing_C]   SUCCESS
[21:41:16.705]  [Default__GA_SwordSwing_C]   FAILED  ->  Cooldown
```

Empty log = no file.

---
