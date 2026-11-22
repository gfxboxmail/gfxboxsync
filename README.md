# GFXBox Sync

A non-destructive Adobe Premiere Pro audio synchronization plugin with a shared standalone desktop workflow.

## Repository layout

- `native-engine/` — cross-platform C++ audio matching library
- `premiere-panel/` — Premiere UXP panel
- `standalone/` — desktop application
- `docs/` — architecture and build documentation

## Status

Scaffolding in progress. The implementation currently defines the shared sync API and project structure; SDK-specific Premiere integration must be added with the Adobe SDK and UXP tooling for the target Premiere versions.
