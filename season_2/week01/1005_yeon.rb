def input_preprocess
  gets.chomp.split(' ').map{ |e| e.to_i }
end

def max(connected_list, weight, max_cache, n)
  if connected_list[n].length == 0
    weight[n]
  elsif max_cache[n] != -1
    max_cache[n]
  else
    result = -1
    connected_list[n].each do |e|
      calc = max(connected_list, weight, max_cache, e)
      result = calc + weight[n] if result == -1 || calc + weight[n] > result
    end
    max_cache[n] = result
    result
  end
end

T = gets.chomp.to_i
T.times do
  n,k = input_preprocess
  weight = input_preprocess.unshift(nil)
  connected_list = Array.new(n+1){ Array.new }
  max_cache = Array.new(n+1){ -1 }
  k.times do
    start_point, end_point = input_preprocess
    connected_list[end_point].push(start_point)
  end
  w = gets.to_i
  puts max(connected_list, weight, max_cache, w)
end