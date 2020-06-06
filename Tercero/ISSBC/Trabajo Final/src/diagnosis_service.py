from .observable_repository import ObservableRepository

class DiagnosisService:

    def __init__(self, observable_repository, hypothesis_repository):
        self.__observable_repository = observable_repository
        self.__hypothesis_repository = hypothesis_repository

    
    def execute(self, failures, domain_id):
        observables = self.__observable_repository.getByDomain(domain_id)
        hypotheses = self.__hypothesis_repository.getByDomain(domain_id)
        solution = []

        for hypothesis in hypotheses:
            if hypothesis.verify(failures):
                solution.append(hypothesis)
        return solution
