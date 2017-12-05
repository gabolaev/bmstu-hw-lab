def calc_integral(a, b, procedure = nil, n = 10_000)
  a, b, n = [a, b, n].map!(&:to_f)
  result = 0
  h = (b - a) / n
  (1..n).each do |index|
    result += if block_given?
                yield(a + h * (index + 0.5))
              else
                procedure.call(a + h * (index + 0.5))
              end
  end; result * h
end
