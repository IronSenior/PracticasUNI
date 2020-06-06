

class Hypothesis:

    def __init__(self, hypothesis_id, domain_id, name, description, observables):
        self.__hypothesis_id = hypothesis_id
        self.__domain_id = domain_id
        self.__name = name
        self.__description = description
        self.__observables = observables


    @property
    def observables(self):
        return self.__observables

    @property
    def name(self):
        return self.__name

    @property
    def domain_id(self):
        return self.__domain_id

    @property
    def hypothesis_id(self):
        return self.__hypothesis_id

    @property
    def description(self):
        return self.__description
    

    def verify(self, failures):
        for fail in failures:
            if fail not in self.__observables:
                return False
        return True