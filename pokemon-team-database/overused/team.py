# Author: William Granados
# Date: 01/02/15
# Purpose: This class will simply contain the constructs of a team

class team:
  ''' This class will hold a brief team description and the members of the each
      respective team along with their sets.
  '''


  def __init__(self, team_description, team_members, team_sets):
    ''' (str, [str], {str:str}) -> None
        Creates a basic team
    '''
    self._team_description = team_description
    self._team_members = team_members
    self._team_sets = team_sets
    self._team_members.sort() # we do this to help with the hashing


  def __hash__(self):
    '''  uses md5 hashing algorithm to hash the name of the members
    '''
    return hash(str(team_members))


  def __str__(self):
    ''' returns a string representaiton of everything
    '''
    ret = 'Team Description:\n'
    ret += str(self._team_description) + '\n'
    ret += 'Team Sets:\n'
    for i in range(len(self._team_members)):
        ret += str(self._team_sets[self._team_members[i]]) + '\n'
    return ret

  # getters and setters
  def getTeamDescription(self):
      return self._team_description

  def setTeamDescription(self, team_description):
      self._team_description = team_description

  def getTeamMembers(self):
      return self._team_members

  def setTeamMembers(self, team_members):
      self._team_members = _team_members

  def getTeamSets(self,team_sets):
      self._team_sets = team_sets




#debugging goes on here
# if __name__ == '__main__':
#    sample_set = 'Azumarill @ Choice Band \n \
#                 Ability: Huge Power \n \
#                 EVs: 172 HP / 252 Atk / 84 Spe \n \
#                 Adamant Nature \n \
#                 - Play Rough \n \
#                 - Waterfall \n \
#                 - Aqua Jet\n \
#                 - Superpower'
#    team_description = 'testing team'
#    team_members = ['azumarill','charizard']
#    team_sets = {'azumarill':sample_set,'charizard':'dragon claw'}
#    myteam = team(team_description,team_members,team_sets)
#    database = {myteam:1}
#    print(myteam)