i = gets.chomp.to_i
nums = [[1,0],[0,1]]
while nums.length < 41
  nums.push([nums[-1][0] + nums[-2][0], nums[-1][1] + nums[-2][1]])
end
i.times do
  n = gets.chomp.to_i
  puts "#{nums[n][0]} #{nums[n][1]}"
end