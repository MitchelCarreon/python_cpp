from abc import ABC, abstractmethod


class Pattern:
    def __init__(self, image):
        self._image = image

    def __str__(self):
        return f'{type(self).__name__}'

    @abstractmethod
    def create(self):
        print(f'Creating {self}...')

