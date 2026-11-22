# GFXBox Sync architecture

## Non-destructive behavior

The plugin never modifies source media. Proposed offsets are applied as timeline clip moves after an explicit user confirmation. An undo command or Premiere history entry should restore the previous arrangement.

## Audio workflow

1. Export or read temporary low-resolution mono copies of selected clip audio.
2. Normalize and resample audio in the native engine.
3. Search for the strongest cross-correlation and return offset plus confidence.
4. Present a preview and confidence score.
5. Apply only non-destructive clip-position changes.

## Next implementation work

- Decode WAV, MP4, MOV, MP3, AAC, and Premiere-supported audio via ffmpeg or SDK APIs.
- Integrate real Premiere clip enumeration and timeline writes.
- Replace the basic correlation engine with FFT/chroma fingerprint matching.
- Add robust confidence thresholds and conflict handling.
- Implement a desktop UI and installers.
