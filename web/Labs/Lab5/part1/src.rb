def calculate(x)
  raise(TypeError) if x.is_a? String
  (Math.log(x) / (Math.cos(x)**2) + x**3 - 5).round(2)
end
