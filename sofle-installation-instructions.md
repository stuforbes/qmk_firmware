# Quantum Mechanical Keyboard Firmware

## Configuration

Config options: 
qmk config user.keyboard=sofle_choc
qmk config user.keymap=stuforbes

Configuration folder: ./keyboards/sofle_choc/keymaps/stuforbes

## Compilation

> qmk compile -e CONVERT_TO=promicro_rp2040

This will produce the file `sofle_choc_stuforbes_promicro_rp2040.uf2` in the qmk_firmware project root folder

## Flashing

1. Plug one half of the keyboard into the computer;
2. Double click the reset button on the keyboard micro-controller. The keyboard will now become a mounted file drive;
3. Copy the compiled uf2 file to the drive. This will automatically unmount the drive and resume as a keyboard;
4. Repeat for the other keyboard half;