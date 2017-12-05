require '../part3/src'

if $PROGRAM_NAME == __FILE__
  puts 'Press ENTER for magic'
  gets
  puts "\nLambda: "
  p calc_integral(0, 1, ->(x) { Math.exp(x) / (x + 1) })
  p calc_integral(0, 2, ->(x) { x * (x - 1) })
  puts "\nBlock: "
  p calc_integral(0, 1) { |x| Math.exp(x) / (x + 1) }
  p calc_integral(0, 2) { |x| x * (x - 1) }
end
