def next_val(k)
  ((-1)**k) / (1..k).inject(:*).to_f
end

def find_with_precision_no_enum(precision)
  raise(TypeError) if precision.is_a? String
  precision = precision.to_f
  now_val = 1.0
  k = 0
  now_val += next_val k += 1 while (now_val - 1 / Math::E).abs > precision
  now_val
end
