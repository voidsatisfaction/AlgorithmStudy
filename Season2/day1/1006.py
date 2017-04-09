# -*- encoding:utf8 -*-

class Area:
    def __init__(self, index, size):
        self.neighbors = []
        self.index = index
        self.size = size

    def addNeighbor(self, neighbor, w):
        if neighbor.size + self.size <= w:
            self.neighbors.append(neighbor)
            neighbor.neighbors.append(self)

    def __repr__(self):
        return str(self.index)

    def delete(self):
        for neighbor in self.neighbors:
            try:
                neighbor.neighbors.remove(self)
            except ValueError:
                pass

class CirclegonAttack:
    def __init__(self, wall_count, sizes, w):
        self.force_size = w
        self.wall_count = wall_count
        self.areas = [Area(i, sizes[i]) for i in xrange(wall_count*2)]
        n = wall_count
        for i in xrange(n):
            self.areas[i].addNeighbor(self.areas[(i+1)%n], w)
            self.areas[n+i].addNeighbor(self.areas[(i+1)%n + n], w)
            self.areas[i].addNeighbor(self.areas[(i+n)%(2*n)], w)

    def calculate_count(self):
        unvisited_set = set(self.areas)
        connections = []

        # group
        while len(unvisited_set) > 0:
            area = unvisited_set.pop()
            connected_set = set()
            todo_list = []
            connected_set.add(area)
            for neighbor in area.neighbors:
                if neighbor in unvisited_set:
                    try:
                        unvisited_set.remove(neighbor)
                    except ValueError:
                        pass
                    todo_list.append(neighbor)
                    connected_set.add(neighbor)
            while len(todo_list) > 0:
                area = todo_list.pop()
                for neighbor in area.neighbors:
                    if neighbor not in connected_set:
                        connected_set.add(neighbor)
                    if neighbor in unvisited_set:
                        try:
                            unvisited_set.remove(neighbor)
                        except ValueError:
                            pass
                        todo_list.append(neighbor)

            connections.append(connected_set)

        # now count
        count = 0
        for connection_set in connections:
            while len(connection_set) >= 2:
                for area in connection_set:
                    if len(area.neighbors) == 0:
                        count += 1
                        try:
                            connection_set.remove(area)
                        except ValueError:
                            pass
                        break
                    if len(area.neighbors) == 1:
                        count += 1
                        neighbor = area.neighbors.pop()
                        try:
                            connection_set.remove(area)
                            connection_set.remove(neighbor)
                            area.delete()
                            neighbor.delete()
                        except ValueError:
                            pass
                        break
                else:
                    # when every connection has more than 2 options
                    # go for whichever - it's same either way
                    area = connection_set.pop()
                    try:
                        connection_set.remove(area)
                        connection_set.remove(neighbor)
                    except KeyError:
                        pass
                    area.delete()
                    neighbor.delete()
            # end of while len(connection_set) >= 2
            if len(connection_set) > 0:
                count += 1
        return count

if __name__ == '__main__':
    for _ in xrange(int(raw_input())):
        n, w = [int(x) for x in raw_input().split()]
        sizes = [int(x) for x in raw_input().split()]
        sizes.extend([int(x) for x in raw_input().split()])
        circlegonAttack = CirclegonAttack(n, sizes, w)
        print circlegonAttack.calculate_count()

# def test():
#     n, w = 3, 100
#     sizes = [51, 49, 51, 51, 51, 51]
#     circlegonAttack = CirclegonAttack(n, sizes, w)
#     print circlegonAttack.calculate_count()
