require_relative '../part2/src'

if $PROGRAM_NAME == __FILE__
  print('Enter the radius of the center of the circle: ')
  rad = gets
  print('Enter the angle of the center of the circle: ')
  degree = gets
  print('Enter the radius of the circle: ')
  radius = gets
  [rad, degree, radius].each do |item|
    raise(TypeError, 'Wrong input value type') unless item =~ /^[0-9]+$/
  end
  circle = Circle.new(rad, degree, radius)
  circle.print_info
  puts 'Circle center cartesian coordinates:'
  puts "x = #{circle.center_x}"
  puts "y = #{circle.center_y}"
end
