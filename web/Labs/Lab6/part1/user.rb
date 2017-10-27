require './src'

if $PROGRAM_NAME == __FILE__
  puts 'Введите точность 1e-4 или 1e-5'
  input = gets
  p 'Ввели', input
  number = input.chomp.to_f
  if [1e-4, 1e-5].include? number
    puts 'Убрали \r\n', number
    puts 'Результат операции: ', find_with_precision_no_enum(number)
  else
    puts 'Введите одно из предложенных выше чисел'
  end
end
