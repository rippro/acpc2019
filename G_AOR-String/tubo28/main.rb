#! /usr/bin/ruby

n = gets.to_i
aor,r_,or_,_a,_ao,o = 0,0,0,0,0,0
n.times {
  s = gets.chomp
  aor += s.scan(/AOR/).size
  r_  += 1 if s =~ /^R/
  or_ += 1 if s =~ /^OR/
  _a  += 1 if s =~ /A$/
  _ao += 1 if s =~ /AO$/
  o   += 1 if s == 'O'
}

x = [_a, or_].min
y = [_ao, r_].min
z = [_a-x, r_-y, o].min
p [x+y+z,n-1].min + aor
