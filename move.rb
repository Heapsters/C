require "humanize"

#
# Simple script to move solutions from its Xcode 
# project strucure and parse
# automatically generated header comments.
#
# ruby move.rb chapter:exercise
#

chapter, ex = ARGV[0].split(":")

chapter = Integer(chapter).humanize
ex = "ex#{ex}"

source_path = "richard_chapters/#{chapter}/#{ex}/#{ex}/main.c"

count = 0
contents = ""

File.readlines(source_path).each do |line|
  if count <= 7
    count += 1
    next
  end
  contents += line
end

to_directory = "chapters/#{chapter}"
to_path = "#{to_directory}/#{ex}.c"

Dir.mkdir(to_directory) unless File.exists?(to_directory)

File.open(to_path, "w+") { |file| file.write(contents) }
