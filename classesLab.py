"""
Author: Wiktoria Uramowska
Date: 16/10/2018
Purpose: Lab task from OOP module, which aim is to practice classes and inheritance in Python
"""


# the base class
class WordGames:
    # _init_ is a special Python method that is being called when an object of the class is constructed
    # in short it is called a constructor
    """
    I constructed a new object, which in this case is also responsible for users input. It is executed first,
    and thanks to that fact, the input from that class can be easily inherited by the other subclasses
    """

    def __init__(self):
        self.sentence = input('Please enter your sentence: ')

    def userSentence(self):
        return self.sentence


"""
subclass responsible for scrambling the letters in the sentence, without moving first and last letter of each word
"""


class WordScramble(WordGames):
    # I used the split() function to separate the words in the string entered by the user
    """
    Constructor. It is using inheritance from the base class WordGames.
    """

    def __init__(self):
        WordGames.__init__(self)

    """
    The for loop first checks the length of the word, if it's less or equal to 3, the program does not change the word
    as there is no point in switching second position with second position
    if the condition is not true, we enter the else, where letter with index 1 is swapped with letter with index 2
    then at the end the word is stored in the finalSentence.
    """

    def changeWords(self):
        finalSentence = ''
        scramble = self.userSentence().split(" ")
        for word in scramble:
            if len(word) <= 3:
                finalSentence += word
                finalSentence += ' '
            else:
                char_arr = list(word)
                temp = char_arr[1]
                char_arr[1] = char_arr[2]
                char_arr[2] = temp
                for character in char_arr:
                    finalSentence += character
                finalSentence += ' '
        print("Your scrambled sentence is:\n\t {}".format(finalSentence))
        return finalSentence


class WordDupli(WordGames):
    """
        Constructor. It is using inheritance from the base class WordGames.
    """

    def __init__(self):
        WordGames.__init__(self)

    """
    The entered string is taken, using the split() function it is divided into separate words.
    I initialized a new variable(local) called finalSentence, in which we store the final sentence with doubled words
    I am using simple assigning operation, which in each iteration of the for loop adds two more words to the final
    output. 
    """

    def changeWords(self):
        mySentence = self.userSentence().split(" ")
        finalSentence = ''
        for word in mySentence:
            finalSentence = finalSentence + word + ' ' + word + ' '
        print("Your doubled sentence is:\n\t {}".format(finalSentence))
        return finalSentence


"""
subclass that demonstrates the Diamond Problem.
"""


class DiamondProblem(WordScramble, WordDupli):
    """
    The ordering of base classes defines the order of search, if the order will be "wrong",
    the error message will display informing about MRO error, which means that the interpreter is
    not able to create a consistent method resolution order.
    """
    def selectChangeWords(self):
        self.changeWords()

    def restructure(self, parent1, parent2):
        self.__class__.__bases__ = (parent1, parent2)


a = DiamondProblem()
a.selectChangeWords()
a.restructure(WordDupli, WordScramble)
a.selectChangeWords()
