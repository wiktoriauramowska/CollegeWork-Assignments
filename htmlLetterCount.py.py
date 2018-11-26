"""
    Author:
        Wiktoria Uramowska
    Date:
        20/11/2018
    Program Description:
        Program that creates new html file that displays the words read in from the text file.
        The size of the words displayed depends on how often the certain word appears in the text.
"""

try:
    # this line is responsible for creating the html file, with write option - allows to write into the file
    fo = open("output.html", "w")
    fo.write('<!DOCTYPE html>\
        <html>\
        <head lang="en">\
        <meta charset="UTF-8">\
        <title>Tag Cloud Generator</title>\
        </head>\
        <body>\
        <div style="text-align: center; vertical-align: middle; font-family: arial; color: white; background-color:black; border:1px solid black">')

    """
        The exception part handles the error of trying to use the text file which is not in the same directory as our
        python file/does not exists at all.
        It would display a message stating that the file that you are trying to use doesn't exist.
    """

    File_Name = 'gettisburg.txt'
    myTextDict={}

    """
        In this part the text file is being opened with read only function, what allows the program to 
        use it to display it later on, calculate the occurrences of each word, etc.
        It allows us to avoid the hard coding the text into the python file.
        The for loop puts each of the words into the dictionary, the word is a key, and the value of it 
        is the number of times it occurs in the text. 
    """
    with open(File_Name,'r') as fh:
        for line in fh:
        # removing punctuation from the text
            words = line.replace('.','').replace('\'','').replace(',','').replace('-','').lower().split()
            for word in words:
                if word not in myTextDict:
                    myTextDict[word] = 1
                else:
                    myTextDict[word] = myTextDict[word] + 1

    """
        In this loop program removes the common stop word, what skips them from the final display.
        It iterates through the words in the dictionary and if the key word is not one of the 
        common words it will display it using the span tag. The size depends on the counter.
    """
    for keyWord in myTextDict:
        commonWords = [ 'of','at','in','without','between','he','they','anybody','it','on','the','a','my',
                        'more','much','either','neither','and','when','while','although','or','be','is',
                        'am','are','have','got','do','no','nor','as','this','to','that','for','those','but',
                        'will','what','us','from','these','not','by']

        if keyWord not in commonWords:
            # calculating the size of word
            count = 10 * myTextDict[keyWord]
            fo.write('<span style="font-size:{}px"> {} </span>'.format(count, keyWord))
        else:
            continue

    fo.write('</div>\
            </body>\
            </html>')

# except part checks if the text file program wants to use exists and if permission is granted 
except FileNotFoundError:
    print("Sorry, the file you are trying to open doesn't exist!")
except PermissionError:
    print("Sorry, you have no permission to access this file!")





