# -*- encoding:utf8 -*-
# building = [build_time, precedents, total_time]

def add_precedent(building1, building2):
    building1[1].append(building2)

def get_total_time(building):
    if building[2] == None:
        if len(building[1]) == 0:
            building[2] = building[0]
        else:
            building[2] = max(
                get_total_time(precedent)
                for precedent in building[1]
            ) + building[0]
    return building[2]

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        n, k = [int(x) for x in raw_input().split()]
        buildings = []

        # read construction time
        for time in raw_input().split():
            buildings.append([int(time), [], None])

        # read construction rule
        for _ in xrange(k):
            s, t = [int(x) for x in raw_input().split()]
            add_precedent(buildings[t-1], buildings[s-1])

        # read target building
        target_index = int(raw_input())-1
        building_target = buildings[target_index]

        print get_total_time(building_target)