# GFXBox Sync build

## Native engine and tests

```bash
cmake -S native-engine -B build/native-engine
cmake --build build/native-engine
ctest --test-dir build/native-engine
```

## Standalone scaffold

```bash
cmake -S standalone -B build/standalone
cmake --build build/standalone
```

## Premiere panel

Package `premiere-panel/` according to the Adobe UXP installation process for the supported host version. Timeline and media integration remain to be connected to the shared native engine.
