#! /usr/bin/ruby

problems = [
  'A',
  'B',
  'C',
  'D',
  'E_Monster_Buster',
  'F_Find_a_Friend',
  'G_AOR-String'
]

problems.zip('A'..'Z').each { |p, s|
  input  = Dir.glob("#{p}/rime-out/tests/*.in")
  output = Dir.glob("#{p}/rime-out/tests/*.diff")
  dst_dir = "submission/data/#{s}_#{p}"
  `mkdir -p #{dst_dir}`
  `cp #{input.join " "} #{dst_dir}`
  `cp #{output.join " "} #{dst_dir}`
}

Dir.chdir("submission/data") {
  Dir.glob("**/*.diff").each { |diff|
    `mv #{diff} #{diff.sub('.diff', '.out')}`
  }
}

checker_dir = 'submission/checker/B_Shortest_Crypt'
`mkdir -p #{checker_dir}`
`cp B/tests/checker.cc #{checker_dir}`
`cp B/tests/testlib.h #{checker_dir}`
`cp B/tests/constraints.hpp #{checker_dir}`
