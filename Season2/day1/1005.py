# -*- encoding:utf8 -*-
class Building:
    def __init__(self, build_time):
        self.build_time = build_time
        self.precedents = []
        self._total_time = None

    def add_precedent(self, building):
        self.precedents.append(building)
    
    def get_total_time(self):
        if self._total_time == None:
            if len(self.precedents) == 0:
                self._total_time = self.build_time
            else:
                self._total_time = max(
                    precedent.get_total_time()
                    for precedent in self.precedents
                ) + self.build_time
        return self._total_time

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        n, k = [int(x) for x in raw_input().split()]
        buildings = []

        # read construction time
        for time in raw_input().split():
            buildings.append(Building(int(time)))

        # read construction rule
        for _ in xrange(k):
            s, t = [int(x) for x in raw_input().split()]
            buildings[t-1].add_precedent(buildings[s-1])

        # read target building
        target_index = int(raw_input())-1
        building_target = buildings[target_index]

        print building_target.get_total_time()