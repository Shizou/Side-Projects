# Author: William Granados
# Date: 01/02/15
# Purpose: This script was made to quickly check if someone is using a team in
# the forum. All you have to do is paste the team members and it will return the
# most relevant results.

from team_database import database

def main():
  d = database()
  print('Welcome to the team lookup!')
  print('Here we will check if a team is currently within our database')
  print('All you have to do is enter the name of six pokemon and we will check')
  print('If at any moment you want to quit simply type \'qq\' without the \' ')
  user_input = ''
  while(user_input != 'qq'):

    user_query = []
    print('Please enter 6 pokemon, 1 per line')
    consent = input('press qq or y to continue\n')
    if(consent == 'qq'):
       break
    for i in range(6):
       pokemon = input()
       user_query.append(pokemon)
    output = d.query(user_query)
    print()
    if(output != None):
       print(output)
    else:
       print('Sorry, we did\'t find anything.')
    user_input = input()

# do your testing here
if __name__ == '__main__':
    main()