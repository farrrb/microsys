# Load executable
file ../out/microsys.elf

# Connect to OpenOCD @localhost
target remote localhost:3333

# Reset the target and halt immediately
monitor reset halt

# Enables disassembly for the next line(s)
#set disassemble-next-line on
