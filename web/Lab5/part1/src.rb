def calculate(x)
  raise(TypeError) unless x.is_a? Numeric
  (Math.log(x) / (Math.cos(x)**2) + x**3 - 5).round(2)
end
