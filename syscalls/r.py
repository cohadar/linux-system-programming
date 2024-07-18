import ctypes
import os

libc = ctypes.CDLL(None)

# Define constants
O_RDONLY = os.O_RDONLY
buffer_size = 1024

# Define the syscalls
open = libc.open
open.argtypes = [ctypes.c_char_p, ctypes.c_int]
open.restype = ctypes.c_int

read = libc.read
read.argtypes = [ctypes.c_int, ctypes.c_void_p, ctypes.c_size_t]
read.restype = ctypes.c_ssize_t

close = libc.close
close.argtypes = [ctypes.c_int]
close.restype = ctypes.c_int

# Open file
fd = open(b"baba", O_RDONLY)
if fd < 0:
    raise OSError("Failed to open file")

# Read file
buffer = ctypes.create_string_buffer(buffer_size)
bytes_read = read(fd, buffer, buffer_size)
if bytes_read < 0:
    raise OSError("Failed to read file")

print(buffer.value[:bytes_read].decode())

# Close file
close(fd)
