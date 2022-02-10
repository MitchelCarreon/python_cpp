from abc import abstractmethod, ABC
import PatternStyles


class PatternFactory(ABC):
    @abstractmethod
    def init(self, image, init_patterns):
        pass


class SimpleTheme(PatternFactory):
    def init(self, image, init_patterns):
        init_patterns.extend([
            PatternStyles.Stripes(image),
            PatternStyles.Waves(image),
                              ])


class ComplexTheme(PatternFactory):
    def init(self, image, init_patterns):
        init_patterns.extend([
            PatternStyles.Psychedelic(image),
        ])