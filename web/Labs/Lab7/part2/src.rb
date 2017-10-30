# Expanded standard class
class Numeric
  def degrees
    self * Math::PI / 180
  end
end

# Point class definition
class Point
  def initialize(input_rad, input_phi)
    @rad = input_rad.to_f
    @phi = input_phi.to_f
  end

  def print_coords
    puts("Rad = #{@rad}, Degree = #{@phi}")
  end

  def cartesian_x
    (@rad * Math.cos(@phi.degrees)).round(2)
  end

  def cartesian_y
    (@rad * Math.sin(@phi.degrees)).round(2)
  end
  attr_reader :rad, :phi
  private :rad, :phi
end

# Circle class definition.
class Circle
  def initialize(center_rad, center_deg, circle_rad)
    @circle_center = Point.new(center_rad, center_deg)
    @circle_rad = circle_rad
  end

  def print_info
    puts 'Circle center polar coordinates:'
    puts @circle_center.print_coords
    puts "Circle radius is a #{@circle_rad}"
  end

  def center_x
    @circle_center.cartesian_x
  end

  def center_y
    @circle_center.cartesian_y
  end

  def center_rad
    @circle_rad
  end
  attr_reader :circle_rad, :circle_center
  private :circle_rad
end
