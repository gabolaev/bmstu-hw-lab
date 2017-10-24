def string_handler(str)
  str.split.each do |i|
    i.tr!('н', 'т') if i[0] == 'н'
    i.tr!('о', 'е') if i[-1] == 'о'
  end.join(' ')
end
