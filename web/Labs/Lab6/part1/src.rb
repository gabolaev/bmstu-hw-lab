def next_val(k)
  ((-1)**k) / (1..k).inject(:*).to_f
end

def find_with_precision_no_enum(precision)
  raise(TypeError) if precision.is_a? String
  precision = precision.to_f
  now_val = 1.0
  k = 0
  prev_val = 0

  while((now_val - prev_val).abs > precision)
    prev_val = now_val
    now_val += next_val(k += 1)

    puts "#{prev_val} => #{now_val}"
  end
  # prev_val += now_val += next_val k += 1 while (now_val - 1 / Math::E).abs > precision
  now_val
end

