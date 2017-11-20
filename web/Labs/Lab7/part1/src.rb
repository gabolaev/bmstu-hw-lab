def create_files
  File.open('F.txt', 'w') do |f|
    rand(10_000).times do
      f.write("#{rand(1000)} \n")
    end
  end

  File.open('F.txt') do |f|
    g = File.open('G.txt', 'w')
    h = File.open('H.txt', 'w')
    f.readlines.each { |line| line.to_i.even? ? g.write(line) : h.write(line) }
    g.close
    h.close
  end
end
