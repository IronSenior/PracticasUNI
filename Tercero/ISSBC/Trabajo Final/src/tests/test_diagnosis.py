import unittest
import uuid
import unittest

from unittest.mock import MagicMock

from ..hypothesis import Hypothesis
from ..observable import Observable
from ..domain import Domain
from ..diagnosis_service import DiagnosisService


from ..hypothesis_repository import HypothesisRepository
from ..domain_repository import DomainRepository
from ..observable_repository import ObservableRepository



class TestDiagnosis(unittest.TestCase):

    def test_diagnosis(self):
        domain_id = uuid.uuid4()

        tos = Observable(uuid.uuid4(), domain_id, "Tos", "Tiene tos", "boolean")
        tos.setValue(True)
        mocos = Observable(uuid.uuid4(), domain_id, "Mocos", "Tiene Mocos", "boolean")
        mocos.setValue(True)
        observables = [tos, mocos]
        resfriado = Hypothesis(uuid.uuid4(), domain_id, "Resfriado", "Estas malito", observables)

        fiebre = Observable(uuid.uuid4(), domain_id, "Fiebre", "Tiene Fiebre", "boolean")
        fiebre.setValue(True)
        observables = [fiebre, tos]
        covid = Hypothesis(uuid.uuid4(), domain_id, "Covid", "Estas muy malito", observables)


        observable_repository = MagicMock()
        observable_repository.getByDomain = MagicMock(return_value=[
            tos, mocos, fiebre
        ])

        hypothesis_repository = MagicMock()
        hypothesis_repository.getByDomain = MagicMock(return_value=[
           resfriado, covid
        ])

        diagnosis_service = DiagnosisService(observable_repository, hypothesis_repository)
        fallos = [tos, mocos]
        result = [resfriado]

        self.assertEqual(result, diagnosis_service.execute(fallos, domain_id))