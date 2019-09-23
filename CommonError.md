# Nuke Common Error and Solutions

### Rotoshape not showing via alpha channel
Solution: 
- Nuke Preferences > Panels > viewer 
- viewer buffer bit depth "half-float" 
- enable "use GPU for viewer when possible" 
- enable "disable GPU viewer dithering" 
- restart Nuke


### Rotoshape lag in viewer (Nuke11 on Linux and MacOS)
Solution:
- set ENV variable 'QT_COMPRESS_TABLET_EVENTS'='1' (**1 has to be string**)
- in `menu.py` add line `os.setenv('QT_COMPRESS_TABLET_EVENTS')='1'`
- **OR** in cshell/terminal, `setenv QT_COMPRESS_TABLET_EVENTS 1`
- restart nuke
