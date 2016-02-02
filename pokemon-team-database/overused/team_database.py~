# Author: William Granados
# Date: 01/02/15
# Purpose: This class will simply handle queries related to teams

from team import team
import text_file_handler

class database:
  ''' This class will hold all available teams currently in the forum
  '''
  def __init__(self):
    ''' default constructor
        we will just have a list of
    '''
    self._teams = text_file_handler.retrieve_teams()
    self._database = {}
    for team in self._teams:
        self._database[str(team.getTeamMembers())] = team

  def query(self, team):
    ''' (list of str) -> team
        checks if the team is in the database
    '''
    team.sort()
    team = str(team)
    if team in self._database:
       return self._database[team]
    else:
       return None


if __name__ == '__main__':
  d = database()
  q = ['Excadrill', 'Heatran', 'Latios-Mega (M)', 'Manaphy', 'Tangrowth', \
  'Tyranitar']
  print(d.query(q))
  # Yay, I'm finally done (It was almost 7am when I finished this, please
  # understand my joy)

