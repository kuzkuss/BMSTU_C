import ctypes

lib = ctypes.CDLL('libarr.dll', winmode=0)

_fill_primes = lib.fill_primes

_fill_primes.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_primes.restype = None

def fill_primes(n):
    arr = (ctypes.c_int * n)()
    
    _fill_primes(arr, n)
    
    return list(arr)


_filter = lib.filter

_filter.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
                    ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_filter.restype = ctypes.c_int

def filter_1(arr, val):
  n = len(arr)
  src_arr = (ctypes.c_int * n)(*arr)
  res = (ctypes.c_int * (n + 1))()
  
  n_res = ctypes.c_int(n + 1)
  
  rc = _filter(src_arr, n, res, n_res, val)
  
  return rc, list(res)

def filter_2(arr, val):
  n = len(arr)
  src_arr = (ctypes.c_int * n)(*arr)
  
  n_res = ctypes.c_int(0)
  
  rc = _filter(src_arr, n, None, n_res, val)
  if rc:
    res = (ctypes.c_int * n_res.value)()
	
    rc = _filter(src_arr, n, res, n_res, val)
	
    return rc, list(res)	
  else:
    return rc, list()

print('Enter amount of elements:')
n = int(input())

if n > 0:
    arr = fill_primes(n)
    print("Source array:")
    print(arr)
    print("Enter memory allocation method:")
    print("1 - Estimation of the maximum possible array size and memory allocation with a margin")
    print("2 - Making the first call to the function to find out the required size of the array, allocating memory and calling the function again")
    choice = int(input())
    print("Enter value to insert:")
    val = int(input())
    if choice == 1:
            rc, res_arr = filter_1(arr, val)
            print("Result:")
            print(res_arr)
    elif choice == 2:
            rc, res_arr = filter_2(arr, val)
            print("Result:")
            print(res_arr)
    else:
        print("Incorrect choice")

else:
    print("Incorrect amount of elements")