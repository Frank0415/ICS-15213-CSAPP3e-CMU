def f(x):
    return not (~x + 1)

def test(x,y,z):
    temp =  bool(~(not x)+ (1))
    return (not temp and y) or ((temp) and z)

def is_nan(uf):
    NAN_mask = ~(0xFF << 23)
    if not ((NAN_mask & uf) >> 23) and (uf << 9):
        return True
    return False

# Test the is_nan function
print(is_nan(0x7F800001))  # NaN value, should return True
print(is_nan(0x7F800000))  # Infinity, should return False
print(is_nan(0x3F800000))  # 1.0, should return False

print(test(0,4,5))
print(test(2,4,5))
