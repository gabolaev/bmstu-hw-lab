# Who da fook is rubocop?
class Calculator
  def calculate(x, y)
      [x,y].map {|i| if i.is_a? String
                       raise(TypeError)
                     end
      }
    (Math.log(x) / (Math.cos(x)**2) + x**3 - 5).round(2)
  end
end
