import sys

itemOfInterest=sys.argv[1]

import os 
os.system(f"mkdir {itemOfInterest}")
locations = ['kyiv_ukraine', 'tokyo_japan', 'sydney_australia', 'london_england', 'toronto_canada', 'singapore', 'new-delhi_india', 'iceland', 'beijing_china', 'cape-town_south-africa', 'hamilton_canada', 'tehran_iran', 'new-york_usa', 'rio-de-janeiro_brazil', 'golden-horseshoe_canada', 'cairo_egypt', 'saint-helena', 'interlaken_switzerland', 'hong-kong_china']
for loc in reversed(locations):
    print(loc)
    os.system(f"../mapper{itemOfInterest} /cad2/ece297s/public/maps/{loc}.streets.bin > {itemOfInterest}/{itemOfInterest}_{loc}.txt;")
    print("done")
