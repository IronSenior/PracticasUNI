import os

from .hypothesis import Hypothesis
from .observable_repository import ObservableRepository

from uuid import UUID
import sqlalchemy as db


class HypothesisRepository:

    def __init__(self):
        self.__db_engine = db.create_engine(os.getenv('DB_ENGINE'))
        self.__db_connection = self.__db_engine.connect()
        self.__db_metadata = db.MetaData()
        self.__hypothesis = db.Table("hypothesis", self.__db_metadata,
                                autoload=True, autoload_with=self.__db_engine)
        self.__hypo_observables = db.Table("hypo_observables", self.__db_metadata,
                                autoload=True, autoload_with=self.__db_engine)

    def add(self, hypothesis: Hypothesis):
        query = db.insert(self.__hypothesis).values(
                    hypothesis_id=str(hypothesis.hypothesis_id), 
                    domain_id=hypothesis.domain_id,
                    name=hypothesis.name,
                    description=hypothesis.description
                )
        resultProxy = self.__db_connection.execute(query)

        for observable in hypothesis.observables:
            query = db.insert(self.__hypo_observables).values(
                        hypothesis_id=str(hypothesis.hypothesis_id), 
                        observable_id=observable.observable_id,
                        value=observable.value
                    )
            resultProxy = self.__db_connection.execute(query)


    def delete(self, hypothesis: Hypothesis):
        query = db.delete(self.__hypothesis).where(
            self.__hypothesis.columns.hypothesis_id == hypothesis.hypothesis_id)
        resultProxy = self.__db_connection.execute(query)

        query = db.delete(self.__hypo_observables).where(
            self.__hypo_observables.columns.hypothesis_id == hypothesis.hypothesis_id)
        resultProxy = self.__db_connection.execute(query)


    def getById(self, hypothesis_id: UUID):
        query = db.select([self.__hypothesis]).where(
            self.__hypothesis.columns.hypothesys_id == hypothesis_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None
        return self.__getHypothesisFromResult(resultSet[0])


    def getByDomain(self, domain_id):
        query = db.select([self.__hypothesis]).where(
            self.__hypothesis.columns.domain_id == domain_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None

        hypothesis = []
        for result in resultSet:
            hypothesis.append(self.__getHypothesisFromResult(result))
        return hypothesis


    def __getHypothesisFromResult(self, result: tuple):
        observables = self.__getObservablesFromHypothesis(result[0])
        return Hypothesis(
            hypothesis_id = UUID(result[0]),
            domain_id = result[1],
            name = result[2],
            description = result[3],
            observables = observables
        )

    def __getObservablesFromHypothesis(self, hypothesis_id):
        query = db.select([self.__hypo_observables]).where(
            self.__hypo_observables.columns.hypothesis_id == hypothesis_id)
        resultProxy = self.__db_connection.execute(query)
        resultSet = resultProxy.fetchall()
        if not resultSet:
            return None

        observables = []
        observable_repository = ObservableRepository()
        for result in resultSet:
            observable = observable_repository.getById(result[1])
            observable.setValue(True) # TODO lack of time
            observables.append(observable)
        return observables
        


    