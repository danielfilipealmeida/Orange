# Orange
Simple VJing app made with openFrameworks

**Orange** is the remake of **Carob**, a VJing software using *openFrameworks*.

## Configuration

To compile:
 - clone this inside: `<of path>/apps/myApps/`.
 - configure the following paths:
   - CATCHCPP_PATH
   - OF_PATH 

## Instructions

### Keys

#### Layer operations


```
1 - Layer 1
2 - Layer 2
3 - Layer 3
4 - Layer 4
```

*Needing implementation*:

```
shift + 1 - Load visuals to layer 1
shift + 2 - Load visuals to layer 2
shift + 3 - Load visuals to layer 3
shift + 4 - Load visuals to layer 4
```


#### Visual operations

```
q,w,e,r - Trigger visuals on Layer 1 (1st, 2nd, 3rd, and 4th)
a,s,d,f - Trigger visuals on Layer 2 (same)
z,x,c,v - Trigger visuals on Layer 3
```

*Needing implementation*:

```
shift + (q,w,e,r) - Load a visual in a Layer 1 visual slot
shift + (a,s,d,f) - Load a visual in a Layer 2 visual slot
shift + (z,x,c,v) - Load a visual in a Layer 3 visual slot
```
## Work

- Visuals Controller
- Create operations with GLSL.
- Create `PlayModeInterface` for implementing Loop modes (forward loop, backward loop, ping ping, no loop) and random playing
- Unit tests

## TODO

- make all Entitities structs
- create a Video Controller for controlling videos.
- Split GUI into panels
- have a panel for all the loaded videos, that is a list of visuals with a thumbnail and a name
- decorate a int slider to have multiple selections with multiple titles
- have a visual panel
- have a panel with all the visuals in a layer -> layer matrix panel
- decorate panels? to remove options/add options


## Bugs

- Cannot generate thumbnail or get a frame for a videoplayer after load
- `[warning] ofGLRenderer: draw(): texture is not allocated`
- `[warning] Adding another parameter with same name '' to group 'Layers'`
- `[verbose] ofTrueTypeFont: loadFontFace(): ""Menlo Regular"" not a file in data loading system font from ""/System/Library/Fonts/Menlo.ttc""`


