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
  # private :rad, :phi
end

# Circle class definition.
class Circle < Point
  def initialize(center_rad, center_deg, circle_rad)
    super(center_rad, center_deg)
    @circle_rad = circle_rad
  end

  def print_info
    puts 'Circle center polar coordinates:'
    print_coords
    puts "Circle radius is a #{@circle_rad}"
  end

  def center_rad
    @circle_rad
  end
end
