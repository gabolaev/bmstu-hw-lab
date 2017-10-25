require_relative './src'

if $PROGRAM_NAME == __FILE__
  print 'Введите любое положительное число: '
  input = gets
  p 'Ввели', input

  number = input.chomp.to_s
  puts 'Убрали \r\n', number

  if number =~ /^[0-9]+$/
    puts 'Результат операции: ', calculate(number.to_i)
  else
    puts 'Неверный формат числа'
  end
end
