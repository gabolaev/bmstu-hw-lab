require_relative './src'

if $PROGRAM_NAME == __FILE__
  puts 'Введите строки, разделяя слова пробелами. Остановку ввода можно осуществить вводом пустой строки.'

  result_text = input_text = ''
  while (input = readline) && !input.chomp.empty?
    input_text += input
    result_text += format("%s\n", string_handler(input))
  end

  printf("Исходный текст:\n%s\n", input_text)
  printf("Обработанный текст:\n%s\n", result_text)

end
