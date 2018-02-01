
# def next_val(k)
#   ((-1)**k) / (1..k).inject(:*).to_f
# end
#
# def find_with_precision_enum(precision)
#   precision.is_a?(String) ? raise(TypeError) : (precision = precision.to_f)
#   global = 0
#   list = Enumerator.new do |yield_er|
#     sum = 1.0
#     counter = 0.0
#     loop do
#       yield_er.yield sum
#       sum += next_val counter += 1
#       global = sum
#     end
#   end
#   list.take_while { |sum| (1 / Math::E - sum).abs > precision }
#   global
# end


def enum_solve(n_steps, lower_bound, upper_bound)
  step = (upper_bound - lower_bound).abs.to_f / n_steps.to_f
  prev, cur = lower_bound, lower_bound + step
  area = 0

  Enumerator::Lazy.new 1..n_steps do |yielder|
    area += step * (Math.tan(cur)**2 + Math.tan(prev)**2) / 2.0
    prev = cur
    cur += step

    yielder.yield area
  end
end

enum_solve(10,Math::PI / 4.0, Math::PI / 3.0).each do |x|
  p x
end
