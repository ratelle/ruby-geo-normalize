Gem::Specification.new do |s|
  s.name    = "geo-normalize"
  s.version = "0.1.0"
  s.summary = "GeoIP city name normalization"
  s.author  = "Jeremie Lasalle Ratelle"
  
  s.files = Dir.glob("ext/**/*.{c,rb}")
  
  s.extensions << "ext/geo_normalize/extconf.rb"
  
  s.add_development_dependency "rake-compiler"
end