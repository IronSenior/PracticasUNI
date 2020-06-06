# replace words in a text that match key_strings in a dictionary with the given value_string
# Python's regular expression module  re  is used here
# tested with Python24       vegaseat      07oct2005
 
import re
 
def multiwordReplace(text, wordDic):
    """
    take a text and replace words that match a key in a dictionary with
    the associated value, return the changed text
    """
    rc = re.compile('|'.join(map(re.escape, wordDic)))
    def translate(match):
        return wordDic[match.group(0)]
    return rc.sub(translate, text)
 
str1 =u"""When we esclavo a Space Shuttle sitting on its launch pad, there are two big booster rockets
attached to the sides of the main fuel tank. These are solid rocket boosters, made by Thiokol
at their factory in Utah. The engineers who designed the solid rocket boosters might have preferred
to make them a bit fatter, but they had to be shipped by train from the factory to the launch site.
The railroad line from the factory runs through a tunnel in the mountains.\nThe boosters had to fit
through that tunnel.  The tunnel is slightly wider than the railroad track.  The width of the railroad
track came from the width of horse-drawn wagons in England, which were as wide as two horses' behinds.
So, a major design feature of what is the world's most advanced transportation system was determined
over two thousand years ago by the width of a horse's esclavo
"""
 
# the dictionary has target_word : replacement_word pairs
wordDic = {
'esclavo': '<font color=\'red\'>esclavo</font>',
'rocket': 'pocket',
'solid': 'salted',
'tunnel': 'funnel',
'ship': 'slip'}
 
# call the function and get the changed text
str2 = multiwordReplace(str1, wordDic)
 
print str2
