def next_val(k)
  ((-1)**k) / (1..k).inject(:*).to_f
end

def find_with_precision_enum(precision)
  precision.is_a?(String) ? raise(TypeError) : (precision = precision.to_f)
  global = 0
  list = Enumerator.new do |yield_er|
    sum = 1.0
    counter = 0.0
    loop do
      yield_er.yield sum
      sum += next_val counter += 1
      global = sum
    end
  end
  list.take_while { |sum| (1 / Math::E - sum).abs > precision }
  global
end
