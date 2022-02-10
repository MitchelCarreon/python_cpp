from collections import namedtuple
from abc import ABC, abstractmethod


class BaseImage(ABC):
    class _Pixel:
        def __init__(self, red, green, blue):
            self.red = int(red)
            self.green = int(green)
            self.blue = int(blue)

        def __str__(self):
            return f'\n{self.red} {self.green} {self.blue}'

    _dimensions = namedtuple('dimensions', 'width height')

    def __init__(self, dimensions, themes, binary_format):
        self._Dimensions = BaseImage._dimensions(*dimensions)

        self._pixels = list()
        self._patterns = list()

        self._themes = themes

        self._binaryFormat = str(binary_format)

    @abstractmethod
    def read(self, file_name):
        pass

    @abstractmethod
    def draw(self, file_name):
        pass

    @abstractmethod
    def _choose_pattern(self):
        pass

    @abstractmethod
    def _write_to(self, file_name):
        pass

    def size(self):
        return self._Dimensions.width * self._Dimensions.height





